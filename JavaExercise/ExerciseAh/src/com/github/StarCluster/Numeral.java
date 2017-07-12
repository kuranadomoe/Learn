package com.github.StarCluster;

public class Numeral
{
	private int num = 0;
	private int count = 1;
	
	public synchronized void produce()
	{
		num = count++;
		System.out.println("Produce:" + num);
	}
	
	
	public synchronized void consume()
	{
		System.out.println("Consume:" + num);
		num = 0;
	}
}
