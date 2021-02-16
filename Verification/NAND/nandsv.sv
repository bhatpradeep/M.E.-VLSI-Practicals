class nandg;
    logic a;
    logic b;

    function new(input A, input B);
           a = A;
           b = B;
    endfunction
 
    function nandgop;
           return !(a&b);
    endfunction

endclass
