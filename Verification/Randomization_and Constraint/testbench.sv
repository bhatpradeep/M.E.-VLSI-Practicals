module tb_top;

	myPacket pkt;

	initial begin

		
		pkt = new ();

		
		for (int i = 0; i < 15; i++) begin

		
			assert (pkt.randomize ());
			pkt.display ();
		end
	end
endmodule
