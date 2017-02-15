using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace ChatWindow
{
    public partial class MainWindow : Window
    {
        private Socket sender;
        private byte[] bytes;
        private bool connected;
        private string serverIP = "10.27.6.230";
        public Thread thread;
        public Task task;

        public MainWindow()
        {
            InitializeComponent();

            thread = new Thread(OnMsgReceive);
            thread.IsBackground = true;
            thread.Start();

            bytes = new byte[1024];
            connected = false;
            Connect();
        }

        public void Connect()
        {
            while (!connected)
            {
                try
                {
                    IPHostEntry ipHostInfo = Dns.Resolve(serverIP);
                    IPAddress ipAddress = ipHostInfo.AddressList[0];
                    IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

                    sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                    try
                    {
                        sender.Connect(remoteEP);
                        textBlock.Text += $"Socket connected to {sender.RemoteEndPoint.ToString()}";
                        connected = true;
                    }
                    catch (ArgumentNullException) { }
                    catch (SocketException) { }
                    catch (Exception) { }
                }
                catch (Exception) { }
            }
        }

        private void Send(string message)
        {
            message += "\n";
            try
            {
                byte[] msg = Encoding.ASCII.GetBytes(message);
                int bytesSent = sender.Send(msg);
            }
            catch (ArgumentNullException) { }
            catch (SocketException) { }
            catch (Exception) { }
        }

        public void OnMsgReceive()
        {
            try
            {
                while (true)
                {
                    int bytesRec = sender.Receive(bytes);
                    if (bytesRec > 0)
                    {
                        Dispatcher.Invoke(() =>
                        {
                            setText(bytesRec);
                        });
                    }
                }
            }
            catch (ArgumentNullException) { }
            catch (SocketException) { }
            catch (Exception) { }
        }

        public void setText(int bytesRec)
        {
            textBlock.Text += '\n' + "Some other guy: " + Encoding.ASCII.GetString(bytes, 0, bytesRec);
        }

        public void sendButton_Click(object sender, RoutedEventArgs e)
        {
            string message;
            message = "";
            message = textBox.Text;
            Send(message);
            textBox.Clear();
            textBlock.Text += '\n' + "You: " + message;
        }

        ~MainWindow()
        {
            try
            {
                sender.Shutdown(SocketShutdown.Both);
                sender.Close();
            }
            catch (ArgumentNullException) { }
            catch (SocketException) { }
            catch (Exception) { }
        }
    }
}
