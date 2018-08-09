using System;
using System.Collections;
using System.Collections.Generic;

public class Maze {
  int height = 20;
  int width = 20;

  int[,] map;


  Random rand = new Random();

  static void Main ()
  {
    Console.WriteLine("Hello World!");
    GenerateMaze();
  }

  void GenerateMaze ()
  {
    map = new int[width,height];
  }
}