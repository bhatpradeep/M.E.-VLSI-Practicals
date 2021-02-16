class xnorg;
     logic a;
     logic b;

    function new(input A, input B);
          a = A;
          b = B;
    endfunction

    function xnorgop;
          return !(a^b);
    endfunction

endclass
