package test1;

public class FractionalDigit {
	public static void main(String[] args) {
		int d = 13;
		int q = 17;
		int a = 0;
		
		for(int i=1;i<100;i++){
			d=(d*10)%q;
			a=(d*10)/q;
			
		}
		
		System.out.println(a);

	}

}
