using System;
using System.Collections;
using System.Collections.Generic;

namespace HelloWorld
{
	class helloworld {
		static void Main (string[] args) {
			if (args.Length == 0) {
				Console.WriteLine("Hello World!");
				Console.WriteLine("No Arguments Provided!");
			}
			else {
				Console.WriteLine("Hello World!");
				Console.WriteLine("Arguments were: ");
				foreach (argument in args) {
					Console.WriteLine(argument);
				}
			}
			Console.ReadKey();
		}
	}
}
