using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using MVVM_Demo.Model;
using System.Collections.ObjectModel;
using System.Windows.Input;

namespace MVVM_Demo.ViewModel
{
    public class MainViewModel : ViewModelBase
    {
        ObservableCollection<User> users = new ObservableCollection<User>();
        User selectedUser = new User();
        public void Load()
        {
            users = User.GetDummyUsers();
            RaisePropertyChanged(() => Users);
        }

        public MainViewModel()
        {
            LoadCommand = new RelayCommand(Load);
        }
        public User SelectedUser
        {
            get { return selectedUser; }
            set { selectedUser = value; RaisePropertyChanged(() => SelectedUser); }
        }
        public ICommand LoadCommand { get; set; }
        public ObservableCollection<User> Users { get { return users; } }
    }
}