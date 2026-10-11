class Solution {
    public int sumOfSquares(int[] nums) {
         int sum = 0;
         int n = nums.length;
         for(int i = 1; i < nums.length; i++) {
            if(n % i == 0){
                sum += nums[i-1] * nums[i-1];
            }
         }
            sum += nums[n-1] * nums[n-1];
         return sum;
    }
}