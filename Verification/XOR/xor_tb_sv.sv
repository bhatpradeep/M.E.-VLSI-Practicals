module xor_tb;
    xorg xg;
    logic c;

    initial begin
        xg = new(1'b0, 1'b0);
        c = xg.xorgop();
    #5     xg = new(1'b0, 1'b1);
        c = xg.xorgop();
    #5     xg = new(1'b1, 1'b0);
        c = xg.xorgop();
    #5     xg = new(1'b1, 1'b1);
        c = xg.xorgop();
    #5;
    end

endmodule
