class counting;
  protected int count, j, n;
 local int q = 10;                        // Data hiding which is not accessible to outside of class.
  virtual function void opcount(int n);
       $display("count is %0d", count);
  endfunction
endclass
   

   class child_class extends counting;
      
      function void opcount(int n);
      int q = 1;
      count = count+1;
      $display("q value is %0d", q);   //which displays the locally declared q value
      $display("count is %0d", count);

      endfunction 
   endclass

   class child_class1 extends counting;
      function void opcount(int n);
            count = count-1;
       $display("count is %0d", count);

      endfunction 
   endclass

