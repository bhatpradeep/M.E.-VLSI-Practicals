module ha_tb;
  logic sum;
  logic carry;

ha h0;

   initial begin
      h0 = new(1'b0, 1'b0);
      sum = h0.ha_sum();
      carry = h0.ha_carry();

#10   h0 = new(1'b0, 1'b1);
      sum = h0.ha_sum();
      carry = h0.ha_carry();

#10   h0 = new(1'b1, 1'b0);
      sum = h0.ha_sum();
      carry = h0.ha_carry();

#10   h0 = new(1'b1, 1'b1);
      sum = h0.ha_sum();
      carry = h0.ha_carry();

#10;

end

endmodule


