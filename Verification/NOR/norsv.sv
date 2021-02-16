class norg;
  
   logic a;
   logic b;

   function new(input A, input B);
         a = A;
         b = B;
   endfunction

   function norgop;
         return !(a|b);
   endfunction

endclass
