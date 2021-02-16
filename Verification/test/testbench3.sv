module tb_top;
	myPacket p1, p2;
	initial begin
                
		p1 = new (3'h2, 2'h3);
		p1.display ();

	        p2 = new ();
		p2.display ();
	end
endmodule
