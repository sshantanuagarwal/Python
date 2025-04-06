
public class MaxContiGousSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = {-2,-3,4};
				
		System.out.println(maxSum(arr));
	}
	
	public static int maxSum(int [] arr){
		int max_so_far =0;
		int max_ending=0;
		for ( int i=0;i<arr.length;i++){
			max_ending= max_ending+arr[i];
			if(max_ending<0){
				max_ending=0;				
			}
			if(max_so_far<max_ending){
				max_so_far= max_ending;
				
			}
		}
		 return max_so_far;
	}

}
