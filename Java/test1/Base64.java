package test1;


public class Base64 {

	static char[] table = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

	public static String encode(byte[] binaryData) {
	    byte[] to_encode;
	    int equal_symbol_num = 0;
	    StringBuffer ret = new StringBuffer();

		if (binaryData.length % 3 == 1){
			equal_symbol_num = 2;
		    to_encode = new byte[binaryData.length+2];
		    for (int i=0;i<binaryData.length;i++){
		    	to_encode[i] = binaryData[i];
			}
			to_encode[to_encode.length-1] = 0;
			to_encode[to_encode.length-2] = 0;
		}else if (binaryData.length % 3 == 2){
			equal_symbol_num = 1;
			to_encode = new byte[binaryData.length+1];
			for (int i=0;i<binaryData.length;i++){
				to_encode[i] = binaryData[i];
			}
			to_encode[to_encode.length-1] = 0;
		}else{
			to_encode = new byte[binaryData.length];
			for (int i=0;i<binaryData.length;i++){
				to_encode[i] = binaryData[i];
			}
		}

		for (int i=0;i<to_encode.length/3;i++){
			byte[] n = { (byte) ((to_encode[3*i]>>2) & 63),
					(byte) ((to_encode[3*i]<<6>>2 & 63) + (to_encode[3*i+1]>>4 & 15)),
					(byte)(((to_encode[3*i+1]<<4)>>>2 & 63) + (to_encode[3*i+2]>>>6 & 3)),
					(byte)((to_encode[3*i+2]<<2)>>>2 & 63)};
			ret.append(table[n[0]]).append(table[n[1]]).append(table[n[2]]).append(table[n[3]]);
		}
		for (int i=0;i<equal_symbol_num;i++){
			ret.append('=');
		}
		return ret.toString();
	}

	public static byte[] decode(String s) {
		int num=0;
		if (s.indexOf('=')==-1){
			num = s.length()/4*3;
		}else if (s.indexOf('=')==s.length()-1){
			num = s.length()/4*3-1;
		}else if (s.indexOf('=')==s.length()-2){
			num = s.length()/4*3-2;
		}
		byte[] decoded = new byte[num];

		for(int i=0;i<s.length()/4;i++){
			byte[] b = new byte[4];
		    for (int k=0;k<4;k++) {
		        if (s.charAt(4*i+k)=='='){
		        	b[k] = 0;
		        	break;
				}
				for (int j = 0; j < 64; j++) {
					if (s.charAt(4*i+k) == table[j]) {
						b[k] = (byte)j;
						break;
					}
				}
			}
			decoded[i*3] = (byte)((b[0]<<2) + (b[1]>>4 & 3));
			if(i*3+1<decoded.length){
			    decoded[i*3+1] = (byte)(((b[1]&15)<<4) + ((b[2]>>2)&15));
			    decoded[i*3+2] = (byte)(((b[2]&3)<<6)+b[3]);
			}

		}
		return decoded;
	}

	public static void main(String[] args) {
		byte[] a = { 1, 2, 1, -7, -9, 110 };
		String s = encode(a);
		System.out.println(s);
		byte[] b = decode(s);
		for(int i=0;i<b.length;i++) {
			System.out.print(b[i] + " ");
		}
		System.out.println();

	}

}


