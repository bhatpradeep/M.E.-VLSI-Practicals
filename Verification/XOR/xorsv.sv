class xorg;
     logic a;
     logic b;

    function new(input A, input B);
          a = A;
          b = B;
    endfunction

    function xorgop;
          return (a^b);
    endfunction

endclass
