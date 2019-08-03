#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *i,char *);
void add_num(int **, int *, int);

int main(){
   int fn=1;//fn is the number of values in the file, it is also the filename ("fn"+".txt")
   int *nums=NULL;//our array to hold all the values, intially unsorted
   char name[20];//will hold the name of the file to read from
   int size=0;//is the number of values in the file
   time stop, start;//start and stop time from clock
   int t;//for loop itterator

   //loops 15 times so we can read each file with different number of values to be sorted, 
  for( t=0;t<15;t++){
      // int *nums=NULL;
      //char name[20];//me
      //int size=0;
      //time stop, start;

      sprintf(name,"%d",fn);//converts an integer value to a c string,first part of filename**
     strcat(name,".txt");//adds .txt to the C string so we have text file to open **
     // strcpy(name,"test.txt");//adds .txt to the C string so we have text file to open **
     // printf("file name is: %s",name);//print out the file name to be opened**
      fill_array(&nums, &size,name);//passes the file to read to fill array
      //fill_array(&nums, &size);
      //print_array(nums, size);

      //Time the function here
      //printf("Bubble Sort\n");
     // printf("Inserttion Sort\n");
      printf("Merge Sort. Size:%d\n",size);
     // printf("Selection Sort\n");
      gettimeofday(&start, NULL);

      //bubble_sort(nums, size);
      // insertion_sort(nums, size);
      merge_sort(nums, 0, size-1);
      //selection_sort(nums, size);

      gettimeofday(&stop, NULL);

      printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
      printf("Seconds: %d\n\n", stop.tv_sec-start.tv_sec);

      // print_array(nums, size);
      free(nums);
      nums=NULL;
      fn=fn*2;
      size=0;
      memset(name,0,20);
   }


   return 0;
}


/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: 
 * 	size- is accurate number of elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}


/*************************************************
 * Description: this function sorts portions of our array,
 * the sets these portions in our array 
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: nums- has unsorted sections
 * Pre-conditions: nums- has sorted sections 
 * ***********************************************/
void merge(int *nums, int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];

   lower_half=left;  //What is this for?sets the left most array locatoin
   upper_half=mid+1;  //What is this for?sets the right most arrat location

   //What does this loop do?
   //starts from the very left of the lower array and very left of the upper array and compares vales,
   // woking its way to the right of each array; setting the next empty location of our temp array
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      //What does this condition do?
      //if the left value of the lower array is less that the left value of the
      //upper array, set the lower left value to temp next avaliable location,
      // then move to the next value of the lower array.
      if(nums[lower_half]<=nums[upper_half]){
	 temp[i]=nums[lower_half];
	 lower_half++;
      }
      //What does this condition do?
      //if the left value of the upper array is less that the left value of the
      //lower array, set the upper left value to temp next location avaliable,
      // then move to the next value of the upper array.
      else{
	 temp[i]=nums[upper_half];
	 upper_half++;
      }
   }

   //What does this condition and loop do?
   //copies the upper half of the sorted array to temp
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
	 temp[i]=nums[j];
   //What does this else and loop do?
   //copies the lower half our our sorted array to temp
   else
      for(j=lower_half;j<=mid;j++, i++)
	 temp[i]=nums[j];

   //What does this loop do?
   //array gets the sorted portions
   for(j=0,i=left;i<=right;i++,j++)
      nums[i]=temp[j];
}


/*************************************************
 * Description:this function is recursively called to half our array, 
 * Params: array of integers annd the left and right most loction 
 * of our array sections of halfs.
 * Pre-conditions:nums- is unsorted array 
 * Post-conditions: nums- is sorted array
 * Returns: none
 * ***********************************************/
void merge_sort(int *nums, int left, int right) {
   int mid; 
   if(left<right) {
      mid=(right+left)/2;
      //  printf("befor 1 Left:%d Right:%d Mid:%d\n",left,right,mid);
      merge_sort(nums, left, mid);  //what does this call do?calls this function recursivelly sending it the 
      //left half of each section of  the array 
      //  printf("after 1 Left:%d Right:%d Mid:%d\n",left,right,mid);
      merge_sort(nums, mid+1, right); //what does this call do?calls the function recursively sending it the 
      //right half of each section of the array
      merge(nums, left, mid, right);  //what does this call do?this function will sort and set sections of our
      //array.
   }
}


/*************************************************
 * Description:This function takes our array and and sorts the array in ascending order.
 * It does this by making sure that that in each location in the array (x), the value in
 * that loaction is the (xth+1) smallest term, so in the 0 location we have the fist smallest term, in the 1 
 * location we have the second smallest term and so on.
 * Params: array of integers and size of the array
 * Pre-conditions: 
 * 	size- is accurate number of elements in the array >=0
 * Post-conditions: 
 * Returns: 
 * ***********************************************/
void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //What does this loop do?
   //this loop set the location of our value, staring at the first location 
   //and loop stops at the second last location in the array.
   //(min) is the location of where the (i+1) smallest value in our array is. 
   for(i=0; i<size-1; i++) {
      min=i;
      //What does this loop do?
      //this loop comapers the value at our current location 
      //to all the values in our array. If the value at the other location is smaller that
      //the value at our current loaction then (min) will now be the location of the other value.
      //our current value is now the other value and is now compaerd to the rest of the values 
      //after our current value.
      for(j=i; j<size; j++)
	 if(nums[j]<nums[min]) 
	    min=j;
      //What elements are being swaped?
      //temp will hold the valu of our current location, 
      //i- is the location of the (i+1) smallest value should go.
      //so num[i] will get the (i+1) smallest term. (temp) will be moved
      //to where our new (i) term uesd to live.
      temp=nums[i];
      nums[i]=nums[min];
      nums[min]=temp;
   }
}


/*************************************************
 * Description:Insetring sort- This function takes our array and sorts the array in ascending
 * order.it uses two for loop, the outer (for) loop will loop N times where N is the sizes of the array,
 * the inner (for) loop - has two conditions that control the number of loops, condition 1 is that we have to
 * bet at the second element of our array; condition 2 is that the current element we are looking at 
 * must be smaller that the previous element in the array, is these conditons are me we enter the loop,
 * in the loop we move the previous (larger) value to where our current value lives (shift previous value
 * to the right),we now look at the n-2 (n is where our current value lives) if that value is also bigger
 * than our current value we shift it to the right, we continue this till the previous value is not larger
 * than our current value or we are at the first poistion of the array,and our nested loop ends, now 
 * or curernt value is inserted in the location where we the previous value is lowere than our current value,
 * or if we are at the first location we insert it there
 * Params: array of integers and size of the array
 * Params: 
 * Pre-conditions: 
 * 	nums-array of unsorted values
 * 	size- is accurate number of elements in the array >=0
 * Post-conditions: 
 * 	nums- is a sorted arrary(in ascending order)
 * Returns: none
 * ***********************************************/
void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   //this the outer for loop that well itterate throug each element in our array,
   //assign it to temp, after the nesterd for loop it will assign temp to the apporiate 
   //location in our array, based on condition in our nested loop.
   for(i=0; i<size; i++) {
      temp=nums[i]; 
      printf("temp:%d\n",temp);
      //What does this loop do?
      //the fist condition is that we are at a location in the array that is not the first position
      //second condition is that our temp value or current value is less than the the previous value in our
      //array, if this is the case we enter the loopand move the previous value to the position where our temp
      //lives in our array. we check our conditions again, but now we are looking at the value two previous to
      //our current location(if this location exists), if that value is grater that our temp value it is moved
      //one to the right, this continues till we are at the first location or the previous value is less than
      //our current value. 
      for(j=i; j>0 && nums[j-1]>temp; j--) 
	 nums[j]=nums[j-1];
      //What does this statment do?
      //one we are out of the nested loop, we assign temp to the location in the array
      //where the previous value is less that our temp,or if we are at the first location 
      //temp will be put in the first location.
      nums[j]=temp;
   }
}


/*************************************************
 * Description: Bubble Sort- This function takes our array and sorts the array in ascending order.
 *		it uses two loops and a comparitive if statement
 *		outer loop- passes throught the array N times, 
 *		N is the number of elements in our array, for each pass one element is set,
 *		first pass largest element is set, second pass second largest elsment is set 
 *		and so on.
 *		inner loop- starts at the first element(a), compares to the next(b) 
 *		if (a) is > (b) swap, if (a) is swaped (a) is now compared to (c) 
 *		if (a) < (c) no swap and (c) is compared to (d), if (c) is the largest element in our array
 *		(c) is bubbled ( compared and swaped) till (c) is set as the last element in the array
 *		and loop ends, then the process is repeated for setting the second largest element, till 
 *		size-i-1=0, i is the number of passes which is also the number of elements set. 
 * Params: array of integers and size of the array
 * Pre-conditions: 
 * 	nums-pionts to a valid array of integers, is unsorted
 * 	size- is accurate number of elements in the array >=0
 *
 * Post-conditions: 
 * 	nums-pionts to a valid array of integers, is sorted in ascending order
 * Returns: none
 * ***********************************************/
void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   //makes passes through our array, the number os passes depends of the size of our array
   //at the first pass we will set the largest element in the array
   //second pass we will set the second largest element,
   //and this comtinues till all the element are is ascending order.
   for(i=0; i<size; i++) {
      //What does this loop do?
      //the number of times looped depends on the numbers of set elements,each pass one element is set 
      //for each pass we will take one element(a) and compare it to the next adjacent
      //element(b), if the first element(a) is grater than the next(b) we will swap them,
      //then we will caompare (a) with the next element (c), if (c) in not greater there is no swap,
      //and (c) is our new value,  now we look at (c) and compare it to the next element (d).
      //So this inner loop continues
      //till the largest element in the array is in the last pasotion in the array.
      //once a value is set in the array the loop ittereates to one less that the last value set.
      for(j=0; j<size-i-1; j++) {
	 if(nums[j]>nums[j+1]) {
	    temp=nums[j];
	    nums[j]=nums[j+1];
	    nums[j+1]=temp;
	 }

	 print_array(nums, size);
      }
   }
}


/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Pre-conditions:
 * 	nums- points to valid array or NULL
 * 	size- is accurate number of elements in array >=0
 * Post-conditions:
 * 	size- is increased by one and
 * 	nums- points to new array with one more element
 * 	      where the contents are the same with num at the end
 * Returns: none
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}


/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Pre-conditions:
 * 	nums- points to valid array or NULL
 * 	size- is accurate number of elements in array >=0
 * Post-conditions:
 * 	array- pointer is pointing to valid array of integers or NULL 
 * 	size- has a positive integer
 * Returns: none
 * **********************************************/
//void fill_array(int **nums, int *size) {
void fill_array(int **nums, int *size,char* name) {
   FILE *fptr;
   char filename[20], num[10];

   //printf("Enter the filename: ");
   //scanf("%s",filename);
   //fptr=fopen(filename,"r");
   fptr=fopen(name,"r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}
