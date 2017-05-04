using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Hangman.Model
{
	class GameModel
	{

		List<string> word;
		public GameModel(string category)
		{
			Category = category;
			word = new List<string>();
			if (!category.Equals("all"))
			{
				
				var path = Category + ".txt";
				var sr = new StreamReader(path);
				var text = sr.ReadToEnd();
				sr.Close();
				string[] names = text.Split(new char[] { ' ', '\n', '\r' });
				Mistakes = 0;
				Level = 1;
				foreach (string name in names)
				{
					if (name.Length != 0)
						word.Add(name);
				}

			}
			else
			{
				string allText="";

				var sr = new StreamReader("videogames.txt");
				var text = sr.ReadToEnd();
				allText += text;
				allText += '\n';
				sr = new StreamReader("sports.txt");
				text = sr.ReadToEnd();
				allText += text;
				allText += '\n';
				sr = new StreamReader("animals.txt");
				text = sr.ReadToEnd();
				sr.Close();
				allText += text;
				allText += '\n';
				Mistakes = 0;
				Level = 1;
				string[] names = allText.Split(new char[] { ' ', '\n', '\r' });

				foreach (string name in names)
				{
					if (name.Length != 0)
						word.Add(name);
				}
			}
			


			setNextWord();
		}

		public void setNextWord()
		{
			

			Random random = new Random();
			int pickWord = random.Next(0, word.Count);

			ToDiscoverWord = word[pickWord];
			StringBuilder sb = new StringBuilder();
			sb.Capacity = ToDiscoverWord.Length;
			for (int i = 0; i < ToDiscoverWord.Length; i++)
			{
				sb.Append("_");
			}
			UndiscoveredWord = sb.ToString();

		}

		public int Level { get; set; }

		public int Mistakes { get; set; }

		public string UndiscoveredWord { get; set; }

		public string ToDiscoverWord { get; set; }

		public string Category { get; set; }


	}
}
