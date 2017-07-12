package com.github.StarCluster;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Program
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter a file path:");
		String path = input.nextLine();
		
		File file = new File(path);
		if(file.isFile()&&file.exists())
		{
			try
			{
				InputStreamReader read = new InputStreamReader(new FileInputStream(file),"UTF-8");
				BufferedReader textBuff = new BufferedReader(read);
				
				int words = 0;
				boolean pre = false,cur = false;
				
				System.out.println("The textual content:\n");				
				for(String line = null;(line = textBuff.readLine())!=null;)
				{
					System.out.println(line);
					for(int i = 0;i<line.length();++i)
					{
						char ch = line.charAt(i);
						pre = cur;
						cur = ('a'<=ch&&'z'>=ch)||('A'<=ch&&'Z'>=ch)?true:false;
						if(pre&&!cur)
							++words;
					}
				}
				System.out.println("\nThe number of words:" + words);
				
				textBuff.close();
				read.close();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}
		else
		{
			System.out.println("File path error!");
		}
		
		input.close();
	}
	
}
