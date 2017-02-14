using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVM_Demo.Model
{
    public class User : ObservableObject
    {
        private string name;
        private int age;
        private List<string> games = new List<string>();

        public string Name
        {
            get { return name; }
            set { Set(() => Name, ref name, value); }
        }
        public int Age
        {
            get { return age; }
            set { Set(() => age, ref age, value); }
        }
        public List<string> Games
        {
            get { return games; }
            set { Set(() => games, ref games, value); }
        }

        public static ObservableCollection<User> GetDummyUsers()
        {
            ObservableCollection<User> users = new ObservableCollection<User>();

            users.Add(new User { Age = 24, Name = "Sanyika", Games = new List<string> { "COD", "CS", "LOL", "DOTA", "Medal of Honor", "Age of Empires" } });
            users.Add(new User { Age = 12, Name = "Sanyika", Games = new List<string> { "MineCraft", "Sims", "FIFA", "NBA", "LOL", "DOTA" } });

            return users;
        }
    }
}
