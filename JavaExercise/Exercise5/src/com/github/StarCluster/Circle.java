package com.github.StarCluster;

public class Circle
{
	private Point center = null;
	private double r = 0;
	
	
	public Circle(Point p,double r)
	{
		this.center = p;
		this.r = r;
	}
	
	
	public static boolean isCircumscibe(Circle c1,Circle c2)
	{
		return (Math.abs(c1.center.distance(c2.center)-c1.r-c2.r)<0.00001);
	}
	
	
	public static double area(double r)
	{
		return Math.PI * r * r;
	}
	
	
	public static double area(Circle c)
	{
		return c.area();
	}
	
	
	public double area()
	{
		return area(r);
	}
	
	
	public String toString()
	{
		return "\"Ô²ÐÄÊÇ("+center+"),°ë¾¶ = "+r+"\"";
	}
}
