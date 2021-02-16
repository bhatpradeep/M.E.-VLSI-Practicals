virtual class parent_class;
 int count; 
 function opcount();
 begin 
   count = count + 1;
   $display("0%d: count = %0d", $time, count);
 end
 endfunction
endclass
 
class child_class extends parent_class;
   function new();
       begin
          super.opcount();
       end
   endfunction
endclass
