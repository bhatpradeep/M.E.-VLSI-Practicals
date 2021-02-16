class myPacket;

	
	rand   bit [1:0]    mode;
	randc  bit [2:0]    key;

	
	constraint c_mode1 { mode < 3; } 
        constraint c_key1 { key > 2;
                            key < 7; }

    function display ();
      // $display ("Mode : 0x%0h Key : 0x%0h", mode, key);
       $display ("Mode : %0d Key : %0d", mode, key);
    endfunction
endclass

