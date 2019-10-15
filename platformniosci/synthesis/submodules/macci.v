module macci(input  wire  clk,
	         input  wire  clk_en,
			 input  wire  reset,
			 input  wire  [7:0]  n,
			 input  wire  start,
			 output reg   done,
			 input  wire  [31:0] dataa,
			 input  wire  [31:0] datab,
			 output reg   [31:0] result);

  reg signed [63:0] acc;

  always @(posedge clk or posedge reset)
  begin
    if (reset) 
    begin
      acc <= 64'h0;	
      done <= 1'b0;
    end
    else begin
	  done <= 1'b0;
	  if (clk_en & start & (n == 8'd1))
	      begin
          acc  <= {{32{dataa[31]}},dataa} * {{32{datab[31]}},datab};
          done <= 1'b1;
          end
      else if (clk_en & start & (n == 8'd2))
          begin
          acc  <= acc + {{32{dataa[31]}},dataa} * {{32{datab[31]}},datab};
          done <= 1'b1;      	
          end
      else if (clk_en & start & (n == 8'd3))
          begin
          result <= acc[31:0];
          done <= 1'b1;
          end
      else if (clk_en & start & (n == 8'd4))
          begin
          result <= acc[63:32];
          done <= 1'b1;      	
          end
      else if (clk_en & start & (n == 8'hf))
          begin
          result <= 32'h0ECE4530;
          done <= 1'b1;      	
          end
      else if (clk_en & start)
          begin
          result <= 32'hDEADBEEF;
          done   <= 1'b1;
          end
      end
    end

endmodule