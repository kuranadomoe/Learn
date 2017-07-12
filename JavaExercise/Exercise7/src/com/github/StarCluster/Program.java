package com.github.StarCluster;

import java.util.Scanner;

public class Program
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入要加密的数据:");
		StringBuffer encryption = new StringBuffer(input.nextLine());//此处不应当用next,因为next以空格作为分隔符,不符合题意
		for(int i = 0, len = encryption.length(), ch = 0; i < len; ++i)
		{
			ch = (int)encryption.charAt(i);
			if(ch >= 'a' && ch <= 'z')
				ch = ch + 4 > 'z' ? ch + 4 - 'z' + 'a' - 1 : ch + 4;
			else if(ch >= 'A' && ch <= 'Z')
				ch = ch + 4 > 'Z' ? ch + 4 - 'Z' + 'A' - 1 : ch + 4;
			encryption.setCharAt(i,(char)ch);
		}
		System.out.println("加密后的数据为:\n" + encryption);
		
		input.close();
	}

}
