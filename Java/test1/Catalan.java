package test1;

public class Catalan {
	
	public static int answers = 0;
	
	//ÇëÊµÏÖgoº¯Êý
	public static void go(Deque from, Deque to, Stack s) {
		if(from.size()==0&&s.size()==0&&to.size()==7){
			answers++;
			return;
		}
		if(from.size()!=0){
			int k=from.getFirst();
			s.push(k);
			from.removeFirst();
			go(from, to, s);
			s.pop();
			from.addFirst(k);;
		}
		if(s.size()!=0){
			int k=s.pop();
			to.addLast(k);
			go(from, to, s);
			to.removeLast();
			s.push(k);
		}
		return;
		
	}

	public static void main(String[] args) {
		Deque from = new Deque();
		Deque to = new Deque();
		Stack s = new Stack();
		
		for(int i=1;i<=7;i++) {
			from.addLast(i);
		}
		
		go(from, to, s);
		
		System.out.println(answers);
		

	}

}

