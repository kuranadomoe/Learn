package com.github.StarCluster;

import java.util.Map;
import java.util.Hashtable;
import java.util.Scanner;

public class Program
{
	
	@SuppressWarnings("resource")
	public static void main(String[] args)
	{
		System.out.println("Please enter year:");
		Scanner input = new Scanner(System.in);
		int year = input.nextInt();
		
		Map<String, Integer> monthInfo = new Hashtable<String, Integer>();
		
		String[] monthName = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
				"October", "November", "December" };
		int[] monthDays = { 31, ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31,
				31, 30, 31, 30, 31 };
		for (int i = 0; i < 12; ++i)
		{
			monthInfo.put(monthName[i], monthDays[i]);
		}
		
		System.out.println("Enter the month you want to find:");
		try
		{
			String month = input.next();
			if(monthInfo.get(month)==null)
				throw new NullPointerException();
			System.out.println("The number of days in the month is " + monthInfo.get(month) + " days.");
		}
		catch (NullPointerException e)
		{
			System.out.println("Wrong month!Please enter the month name(English).");
		}
		input.close();
	}
	
}
