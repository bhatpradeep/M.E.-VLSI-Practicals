module nandg_tb;
    
    nandg ng;
    logic c;
    
    initial begin
         ng = new(1'b0, 1'b0);
         c = ng.nandgop();
    #5   ng = new(1'b0, 1'b1);
         c = ng.nandgop();
    #5   ng = new(1'b1, 1'b0);
         c = ng.nandgop();
    #5   ng = new(1'b1, 1'b1);
         c = ng.nandgop();
    #5;
    end

endmodule
