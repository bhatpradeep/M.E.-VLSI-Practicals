class org;
    logic a;
    logic b;


    function new(input A, input B);
             a = A;
             b = B;
    endfunction

    function orgop;
             return a|b;
    endfunction
endclass
