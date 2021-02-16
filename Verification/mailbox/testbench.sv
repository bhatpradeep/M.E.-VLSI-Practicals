module tb;
  mbox mbx = new();
   my_class m1 = new();
   my_class2 m2 = new();

  initial begin
    m1.names = mbx;
    m2.list = mbx;

    fork
       m1.send();
       m2.receive();
    join
  end
endmodule
