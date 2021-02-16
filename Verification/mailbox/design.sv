typedef mailbox #(string) mbox;
 
 class my_class;
      mbox names;
  
 task send();
  for(int i = 0; i < 3; i++)
    begin 
       string s = $sformatf("name_%0d", i);
     
       #1 $display("[%0t] my_class : Put %s", $time, s);
       names.put(s);
    end
  endtask
endclass

class my_class2;
   mbox list;
   task receive();
       forever begin
          string s;
          list.get(s);
          $display("[%0t] my_class2 : Got %s", $time, s);
       end
   endtask
endclass


