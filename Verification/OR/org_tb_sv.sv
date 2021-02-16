module org_tb;

  org og;
  logic c;

  initial begin
     og = new(1'b0, 1'b0);
     c = og.orgop();
  
#10
 
     og = new(1'b0, 1'b1);
     c = og.orgop();
 
#10

     og = new(1'b1, 1'b0);
     c = og.orgop();
 
#10
  
     og = new(1'b1, 1'b1);
     c = og.orgop();

   end

endmodule
