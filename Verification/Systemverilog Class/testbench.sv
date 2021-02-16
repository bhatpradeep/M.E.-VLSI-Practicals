module polymorphism;
   
        
          
 

    initial begin
        child_class d = new();
        child_class1 d1 = new();    
        counting c[2];

        c[0] = d;
        c[1] = d1;


      
 
      
      c[0].opcount(5);
      c[0].opcount(5);

      c[1].opcount(5);
      c[1].opcount(5);

    end

endmodule
      
