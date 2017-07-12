package com.github.StarCluster;

import java.util.Scanner;

public class Program
{
	
	public static void main(String[] args) throws NumberFormatException
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter a hexadecimal number:");
		try
		{
			String hex = input.nextLine();
			if (!hex.matches("[A-Fa-f0-9]+"))// 用正则表达式判断是否符合十六进制格式(即只含数字和a-f字母)
				throw new NumberFormatException();
			System.out.println(Integer.parseInt(hex, 16));
		}
		catch (NumberFormatException e)
		{
			System.out.println("Number format exception!");
		}
		finally
		{
			input.close();
		}
		
	}
	
}
