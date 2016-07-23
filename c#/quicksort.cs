/* DESCRIPTION:
 * Implement a quicksort algorythm for an array and present it on an example. 
 */

using System;

namespace Quicksort
{
 class Program
 {
  static void Main()
  {
   Random r = new Random();

   int[] array = new int[25];

   for( var i = 0; i < array.Length; i++ )
   {
    array[i] = r.Next()%100;
   }

   Console.WriteLine( "Array to sort:\n" );
   PrintArray( array );
   Console.WriteLine( "\nSegments sorted in each step are marked red.\n" );
   Quicksort( array );
   PrintArray( array );
   Console.ReadKey();
  }

  static void PrintArray( int[] array )
  {
   foreach( var element in array )
   {
    Console.Write( element+" " );
   }
   Console.Write( '\n' );
  }

  static void PrintArray( int[] array, int low, int high )
  {
   for( var i = 0; i < array.Length; i++ )
   {
    if( i >= low && i <= high )
    {
     Console.ForegroundColor = ConsoleColor.Red;
    }
    else
    {
     Console.ResetColor();
    }

    Console.Write( array[i]+" " );
   }
   Console.Write( '\n' );

   Console.ResetColor();
  }


  static void Quicksort( int[] array )
  {
   Quicksort(array, 0, array.Length-1);
  }

  static void Quicksort( int[] array, int low, int high )
  {
   if( low >= high )
   {
    return;
   }
  
   var pivotIndex = high;
   var pivot = array[pivotIndex];

   for( var i = high; i >= low; i-- )
   {
    if( array[i] > pivot )
    {
     pivotIndex--;
     var temp = array[pivotIndex];
     array[pivotIndex] = array[i];
     array[i] = temp;
    }
   }

   array[high] = array[pivotIndex];
   array[pivotIndex] = pivot;


   PrintArray( array, low, high );


   Quicksort( array, low, pivotIndex-1 );
   Quicksort( array, pivotIndex+1, high );
  }
 }
}