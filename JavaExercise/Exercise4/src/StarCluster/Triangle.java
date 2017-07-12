package StarCluster;

public class Triangle
{
	private int sideA = 0,sideB = 0,sideC = 0;
	
	
	public Triangle(int sideA,int sideB,int sideC) throws Exception
	{
		if(!(sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA))
			throw new Exception("错误的三角形边长.");
		this.sideA = sideA;
		this.sideB = sideB;
		this.sideC = sideC;
	}
	
	
	//利用海伦公式S=√p(p-a)(p-b)(p-c)求三角形面积,p为半周长
	public float Area()
	{
		float p = (float)Circumference() / 2;
		return (float)Math.sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
	}
	
	
	public int Circumference()
	{
		return sideA + sideB + sideC;
	}
}
