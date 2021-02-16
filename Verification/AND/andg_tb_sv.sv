module andg_tb;
 
  andg ag;
  logic c;

  
  initial begin
     ag = new(1'b0, 1'b0);
     c = ag.andgop();
#10  
     ag = new(1'b0, 1'b1);
     c = ag.andgop();
#10
     ag = new(1'b1, 1'b0);
     c = ag.andgop();
#10
     ag = new(1'b1, 1'b1);
     c = ag.andgop();
#10;
  end
endmodule
