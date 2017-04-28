using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Hangman.View
{
	/// <summary>
	/// Interaction logic for UserView.xaml
	/// </summary>
	public partial class UserView : Window
	{
		public UserView()
		{
			InitializeComponent();
			var userViewModel = new ViewModel.UserViewModel();
			userViewModel.LoadUsers();
			listView.DataContext = userViewModel;
			
			

		}

		private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			var user= (Model.UserModel)listView.SelectedItem;
			textBox.Text = user.ImagePath;
			image.Source=new BitmapImage(new Uri(user.ImagePath));
		}
	}
}
