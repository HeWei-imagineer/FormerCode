package test1;

public class Fibo {
	public static void main(String[] args) {
		Fibo f = new Fibo();
		System.out.println(f.fibo1(11)); // 这两种方法哪种效率更高？
		System.out.println(f.fibo2(11));
	}

	public int fibo1(int n) { // 使用方法（函数）递归来实现
		if(n>2){
			return fibo1(n-1)+fibo1(n-2);
		}
		return 1;
		
	}

	public int fibo2(int n) { // 使用循环来实现
		int n1=1,n2=1;
		int num=0;
		if(n>2){
			for(int i=2;i<n;i++){
			  num = n1 + n2;
			  n1 = n2;
			  n2 = num;
		    }
			return num;
		}
		return 1;
				
	}

}
