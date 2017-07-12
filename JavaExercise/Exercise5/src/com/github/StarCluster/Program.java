package com.github.StarCluster;

public class Program
{

	public static void main(String[] args)
	{
		Circle c1 = new Circle(new Point(10,10),10);
		Circle c2 = new Circle(new Point(30,20),5);
		if(Circle.isCircumscibe(c1, c2))
			System.out.println(c1+"和"+c2+"的两圆相切");
		else
			System.out.println(c1+"和"+c2+"的两圆不相切");
		System.out.println(c1+"的面积是"+c1.area());
		System.out.println(c2+"的面积是"+Circle.area(c2));
	}

}
