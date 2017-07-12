package com.github.StarCluster;

public class Point
{
	private int x = 0, y = 0;
	
	
	public Point()
	{
		this(0,0);
	}
	
	
	public Point(int x,int y)
	{
		this.x = x;
		this.y = y;
	}
	
	
	public double distance(Point p)
	{
		return Math.sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
	
	
	public double distance2(Point p)
	{
		return p.distance(this);
	}
	
	
	public String toString()
	{
		return x+","+y;
	}
}
