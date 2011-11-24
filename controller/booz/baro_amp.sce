clear();

// anton : 3.5855 -> 950m

//
// baro sensitivity 45.9mV/kPa  [ ]
// baro range 15-115 kPa
// offset 0.2V at 15kPa
//
// v_sensor_volt = 0.2 + (p_pascal-15000)*45.9e-6
//


function [v] = sensor_of_pressure(p)
  sensor_sensitivity = 45.9e-6 ; // V/Pa
  v = 0.2 + (p-15000)*45.9e-6;
endfunction


//
// amplifier parameters
//
if 0
  R10 = 27e3;
  R5  = 390;
  R6  = 12e3;
  R20 = 560;
  R21 = 680;
else
  R10 = 27e3;
  R5  = 390;
  R6  = 12e3;
  R20 = 150;
  R21 = 680;
end

function [vo] = amplify(vi, off1)
  vo = zeros(1:length(vi));
  for i=1:length(vi)
    v = vi(i) * ( 1 + R10/R6 + R10/R5 + R10/(R20+R21) ) - 5*R10/R5 - off1*R10/(R20+R21);
    if v > 3.3
      vo(i) = 3.3;
    elseif v < 0
      vo(i) = 0;
    else
      vo(i) = v;
    end
  end
endfunction

//
// Compute the pressure from altitude
// see http://en.wikipedia.org/wiki/Barometric_formula
// applied in layer 0, ie 0 to 11000m
//
function [pressure] = pressure_of_alt(h)
  Pb = 101325;    // Static pressure : Pascal
  Tb = 288.15;    // Standard temperature: Kelvin 
  Lb = -0.0065;   // Standard temperature lapse rate: Kelvin/meters
  R  = 8.31432;   // Universal gas constant for air: 8.31432 Nm /(mol·K)
  g0 = 9.80665;   // Gravitational acceleration (9.80665 m/s2)
  M  = 0.0289644; //Molar mass of Earth's air (0.0289644 kg/mol)
  hb = 0;
  
  pressure = Pb*(Tb/(Tb+Lb*(h-hb)))^(g0*M/R/Lb);
  
endfunction


alt_range = -1000:11000;
pressure_range = zeros(1,length(alt_range));
sensor_output =  zeros(1,length(alt_range));
for i=1:length(alt_range)
  pressure_range(i) = pressure_of_alt(alt_range(i));
  sensor_output(i) = sensor_of_pressure(pressure_range(i));
end


vi = 3.1:0.001:4.7;

clf();
subplot(3,1,1);
plot2d(alt_range, pressure_range);
xtitle('pressure vs alt');
ylabel('Pascal');
xlabel('meters');

subplot(3,1,2);
plot2d(alt_range, sensor_output);
xtitle('sensor output vs alt');
ylabel('Volts');
xlabel('meters');

subplot(3,1,3)
off1 = 0;
[vo] = amplify(vi, off1);
k = find(vo > 0);
min_sensor_out = vi(k(1))
plot2d(vi,vo,1);

off1 = 1.65;
[vo] = amplify(vi, off1);
plot2d(vi,vo,2);


off1 = 3.3;
[vo] = amplify(vi, off1);
k = find(vo < 3.3);
max_sensor_out = vi(k($))





plot2d(vi,vo,3);
xtitle('amp output vs sensor output');
ylabel('Volts');
xlabel('Volts');


k = find(sensor_output > max_sensor_out);
min_alt = alt_range(k($))
k = find(sensor_output < min_sensor_out);
max_alt = alt_range(k(1))



gain = 1 + R10/R6 + R10/R5 + R10/(R20+R21)

offset_gain = R10/(R20+R21)


subplot(3,1,2);
//xset("color",5)
xrect(min_alt, max_sensor_out, max_alt-min_alt, max_sensor_out - min_sensor_out);
xstring(5000,3.2,sprintf("altitude range %.0f / %.0f m", min_alt, max_alt));
 