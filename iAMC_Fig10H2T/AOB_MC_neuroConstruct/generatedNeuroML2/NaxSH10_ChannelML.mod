TITLE Mod file for component: Component(id=NaxSH10_ChannelML type=ionChannelHH)

COMMENT

    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.5.0
         org.neuroml.model   v1.5.0
         jLEMS               v0.9.8.7

ENDCOMMENT

NEURON {
    SUFFIX NaxSH10_ChannelML
    USEION na WRITE ina VALENCE 1 ? Assuming valence = 1; TODO check this!!
    
    RANGE gion                           
    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!
    RANGE conductance                       : parameter
    
    RANGE g                                 : exposure
    
    RANGE fopen                             : exposure
    RANGE m_instances                       : parameter
    
    RANGE m_alpha                           : exposure
    
    RANGE m_beta                            : exposure
    
    RANGE m_tau                             : exposure
    
    RANGE m_inf                             : exposure
    
    RANGE m_rateScale                       : exposure
    
    RANGE m_fcond                           : exposure
    RANGE m_forwardRate_rate                : parameter
    RANGE m_forwardRate_midpoint            : parameter
    RANGE m_forwardRate_scale               : parameter
    
    RANGE m_forwardRate_r                   : exposure
    RANGE m_reverseRate_rate                : parameter
    RANGE m_reverseRate_midpoint            : parameter
    RANGE m_reverseRate_scale               : parameter
    
    RANGE m_reverseRate_r                   : exposure
    RANGE m_timeCourse_TIME_SCALE           : parameter
    RANGE m_timeCourse_VOLT_SCALE           : parameter
    
    RANGE m_timeCourse_t                    : exposure
    RANGE m_q10Settings_q10Factor           : parameter
    RANGE m_q10Settings_experimentalTemp    : parameter
    RANGE m_q10Settings_TENDEGREES          : parameter
    
    RANGE m_q10Settings_q10                 : exposure
    RANGE h_instances                       : parameter
    
    RANGE h_alpha                           : exposure
    
    RANGE h_beta                            : exposure
    
    RANGE h_tau                             : exposure
    
    RANGE h_inf                             : exposure
    
    RANGE h_rateScale                       : exposure
    
    RANGE h_fcond                           : exposure
    RANGE h_steadyState_rate                : parameter
    RANGE h_steadyState_midpoint            : parameter
    RANGE h_steadyState_scale               : parameter
    
    RANGE h_steadyState_x                   : exposure
    RANGE h_forwardRate_rate                : parameter
    RANGE h_forwardRate_midpoint            : parameter
    RANGE h_forwardRate_scale               : parameter
    
    RANGE h_forwardRate_r                   : exposure
    RANGE h_reverseRate_rate                : parameter
    RANGE h_reverseRate_midpoint            : parameter
    RANGE h_reverseRate_scale               : parameter
    
    RANGE h_reverseRate_r                   : exposure
    RANGE h_timeCourse_TIME_SCALE           : parameter
    RANGE h_timeCourse_VOLT_SCALE           : parameter
    
    RANGE h_timeCourse_t                    : exposure
    RANGE h_q10Settings_q10Factor           : parameter
    RANGE h_q10Settings_experimentalTemp    : parameter
    RANGE h_q10Settings_TENDEGREES          : parameter
    
    RANGE h_q10Settings_q10                 : exposure
    RANGE m_forwardRate_x                   : derived variable
    RANGE m_reverseRate_x                   : derived variable
    RANGE m_timeCourse_V                    : derived variable
    RANGE m_timeCourse_ALPHA                : derived variable
    RANGE m_timeCourse_BETA                 : derived variable
    RANGE m_tauUnscaled                     : derived variable
    RANGE h_forwardRate_x                   : derived variable
    RANGE h_reverseRate_x                   : derived variable
    RANGE h_timeCourse_V                    : derived variable
    RANGE h_timeCourse_ALPHA                : derived variable
    RANGE h_timeCourse_BETA                 : derived variable
    RANGE h_tauUnscaled                     : derived variable
    RANGE conductanceScale                  : derived variable
    RANGE fopen0                            : derived variable
    
}

UNITS {
    
    (nA) = (nanoamp)
    (uA) = (microamp)
    (mA) = (milliamp)
    (A) = (amp)
    (mV) = (millivolt)
    (mS) = (millisiemens)
    (uS) = (microsiemens)
    (molar) = (1/liter)
    (kHz) = (kilohertz)
    (mM) = (millimolar)
    (um) = (micrometer)
    (umol) = (micromole)
    (S) = (siemens)
    
}

PARAMETER {
    
    gmax = 0  (S/cm2)                       : Will be changed when ion channel mechanism placed on cell!
    
    conductance = 1.0E-5 (uS)
    m_instances = 3 
    m_forwardRate_rate = 2.88 (kHz)
    m_forwardRate_midpoint = -20 (mV)
    m_forwardRate_scale = 7.2 (mV)
    m_reverseRate_rate = 0.89280003 (kHz)
    m_reverseRate_midpoint = -20 (mV)
    m_reverseRate_scale = -7.2 (mV)
    m_timeCourse_TIME_SCALE = 1 (ms)
    m_timeCourse_VOLT_SCALE = 1 (mV)
    m_q10Settings_q10Factor = 2 
    m_q10Settings_experimentalTemp = 297.15 (K)
    m_q10Settings_TENDEGREES = 10 (K)
    h_instances = 1 
    h_steadyState_rate = 1 
    h_steadyState_midpoint = -40 (mV)
    h_steadyState_scale = -4 (mV)
    h_forwardRate_rate = 0.045 (kHz)
    h_forwardRate_midpoint = -35 (mV)
    h_forwardRate_scale = 1.5 (mV)
    h_reverseRate_rate = 0.015000001 (kHz)
    h_reverseRate_midpoint = -35 (mV)
    h_reverseRate_scale = -1.5 (mV)
    h_timeCourse_TIME_SCALE = 1 (ms)
    h_timeCourse_VOLT_SCALE = 1 (mV)
    h_q10Settings_q10Factor = 2 
    h_q10Settings_experimentalTemp = 297.15 (K)
    h_q10Settings_TENDEGREES = 10 (K)
}

ASSIGNED {
    
    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel
    v (mV)
    celsius (degC)
    temperature (K)
    ena (mV)
    ina (mA/cm2)
    
    
    m_forwardRate_x                        : derived variable
    
    m_forwardRate_r (kHz)                  : conditional derived var...
    
    m_reverseRate_x                        : derived variable
    
    m_reverseRate_r (kHz)                  : conditional derived var...
    
    m_timeCourse_V                         : derived variable
    
    m_timeCourse_ALPHA                     : derived variable
    
    m_timeCourse_BETA                      : derived variable
    
    m_timeCourse_t (ms)                    : conditional derived var...
    
    m_q10Settings_q10                      : derived variable
    
    m_rateScale                            : derived variable
    
    m_alpha (kHz)                          : derived variable
    
    m_beta (kHz)                           : derived variable
    
    m_fcond                                : derived variable
    
    m_inf                                  : derived variable
    
    m_tauUnscaled (ms)                     : derived variable
    
    m_tau (ms)                             : derived variable
    
    h_steadyState_x                        : derived variable
    
    h_forwardRate_x                        : derived variable
    
    h_forwardRate_r (kHz)                  : conditional derived var...
    
    h_reverseRate_x                        : derived variable
    
    h_reverseRate_r (kHz)                  : conditional derived var...
    
    h_timeCourse_V                         : derived variable
    
    h_timeCourse_ALPHA                     : derived variable
    
    h_timeCourse_BETA                      : derived variable
    
    h_timeCourse_t (ms)                    : conditional derived var...
    
    h_q10Settings_q10                      : derived variable
    
    h_rateScale                            : derived variable
    
    h_alpha (kHz)                          : derived variable
    
    h_beta (kHz)                           : derived variable
    
    h_inf                                  : derived variable
    
    h_tauUnscaled (ms)                     : derived variable
    
    h_tau (ms)                             : derived variable
    
    h_fcond                                : derived variable
    
    conductanceScale                       : derived variable
    
    fopen0                                 : derived variable
    
    fopen                                  : derived variable
    
    g (uS)                                 : derived variable
    rate_m_q (/ms)
    rate_h_q (/ms)
    
}

STATE {
    m_q  
    h_q  
    
}

INITIAL {
    ena = 67.0
    
    temperature = celsius + 273.15
    
    rates()
    rates() ? To ensure correct initialisation.
    
    m_q = m_inf
    
    h_q = h_inf
    
}

BREAKPOINT {
    
    SOLVE states METHOD cnexp
    
    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=NaxSH10_ChannelML type=ionChannelHH), from conductanceScaling; null
    ? Path not present in component, using factor: 1
    
    conductanceScale = 1 
    
    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=NaxSH10_ChannelML type=ionChannelHH), from gates; Component(id=m type=gateHHratesTau)
    ? multiply applied to all instances of fcond in: <gates> ([Component(id=m type=gateHHratesTau), Component(id=h type=gateHHratesTauInf)]))
    fopen0 = m_fcond * h_fcond ? path based
    
    fopen = conductanceScale  *  fopen0 ? evaluable
    g = conductance  *  fopen ? evaluable
    gion = gmax * fopen 
    
    ina = gion * (v - ena)
    
}

DERIVATIVE states {
    rates()
    m_q' = rate_m_q 
    h_q' = rate_h_q 
    
}

PROCEDURE rates() {
    
    m_forwardRate_x = (v -  m_forwardRate_midpoint ) /  m_forwardRate_scale ? evaluable
    if (m_forwardRate_x  != 0)  { 
        m_forwardRate_r = m_forwardRate_rate  *  m_forwardRate_x  / (1 - exp(0 -  m_forwardRate_x )) ? evaluable cdv
    } else if (m_forwardRate_x  == 0)  { 
        m_forwardRate_r = m_forwardRate_rate ? evaluable cdv
    }
    
    m_reverseRate_x = (v -  m_reverseRate_midpoint ) /  m_reverseRate_scale ? evaluable
    if (m_reverseRate_x  != 0)  { 
        m_reverseRate_r = m_reverseRate_rate  *  m_reverseRate_x  / (1 - exp(0 -  m_reverseRate_x )) ? evaluable cdv
    } else if (m_reverseRate_x  == 0)  { 
        m_reverseRate_r = m_reverseRate_rate ? evaluable cdv
    }
    
    m_timeCourse_V = v /  m_timeCourse_VOLT_SCALE ? evaluable
    m_timeCourse_ALPHA = m_alpha  *  m_timeCourse_TIME_SCALE ? evaluable
    m_timeCourse_BETA = m_beta  *  m_timeCourse_TIME_SCALE ? evaluable
    if (( m_timeCourse_ALPHA  +  m_timeCourse_BETA ) == 0)  { 
        m_timeCourse_t = 0.0  *  m_timeCourse_TIME_SCALE ? evaluable cdv
    } else if (1/( ( m_timeCourse_ALPHA  +  m_timeCourse_BETA ) *  m_rateScale  )  < ( 0.02 ))  { 
        m_timeCourse_t = ( (0.02 *  m_rateScale ) ) *  m_timeCourse_TIME_SCALE ? evaluable cdv
    } else  { 
        m_timeCourse_t = ( 1/( m_timeCourse_ALPHA  +  m_timeCourse_BETA )) *  m_timeCourse_TIME_SCALE ? evaluable cdv
    }
    
    m_q10Settings_q10 = m_q10Settings_q10Factor ^((temperature -  m_q10Settings_experimentalTemp )/ m_q10Settings_TENDEGREES ) ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=m type=gateHHratesTau), from q10Settings; Component(id=null type=q10ExpTemp)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10ExpTemp)]))
    m_rateScale = m_q10Settings_q10 ? path based
    
    ? DerivedVariable is based on path: forwardRate/r, on: Component(id=m type=gateHHratesTau), from forwardRate; Component(id=null type=HHExpLinearRate)
    m_alpha = m_forwardRate_r ? path based
    
    ? DerivedVariable is based on path: reverseRate/r, on: Component(id=m type=gateHHratesTau), from reverseRate; Component(id=null type=HHExpLinearRate)
    m_beta = m_reverseRate_r ? path based
    
    m_fcond = m_q ^ m_instances ? evaluable
    m_inf = m_alpha /( m_alpha + m_beta ) ? evaluable
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=m type=gateHHratesTau), from timeCourse; Component(id=null type=NaxSH10_ChannelML_m_tau_tau)
    m_tauUnscaled = m_timeCourse_t ? path based
    
    m_tau = m_tauUnscaled  /  m_rateScale ? evaluable
    h_steadyState_x = h_steadyState_rate  / (1 + exp(0 - (v -  h_steadyState_midpoint )/ h_steadyState_scale )) ? evaluable
    h_forwardRate_x = (v -  h_forwardRate_midpoint ) /  h_forwardRate_scale ? evaluable
    if (h_forwardRate_x  != 0)  { 
        h_forwardRate_r = h_forwardRate_rate  *  h_forwardRate_x  / (1 - exp(0 -  h_forwardRate_x )) ? evaluable cdv
    } else if (h_forwardRate_x  == 0)  { 
        h_forwardRate_r = h_forwardRate_rate ? evaluable cdv
    }
    
    h_reverseRate_x = (v -  h_reverseRate_midpoint ) /  h_reverseRate_scale ? evaluable
    if (h_reverseRate_x  != 0)  { 
        h_reverseRate_r = h_reverseRate_rate  *  h_reverseRate_x  / (1 - exp(0 -  h_reverseRate_x )) ? evaluable cdv
    } else if (h_reverseRate_x  == 0)  { 
        h_reverseRate_r = h_reverseRate_rate ? evaluable cdv
    }
    
    h_timeCourse_V = v /  h_timeCourse_VOLT_SCALE ? evaluable
    h_timeCourse_ALPHA = h_alpha  *  h_timeCourse_TIME_SCALE ? evaluable
    h_timeCourse_BETA = h_beta  *  h_timeCourse_TIME_SCALE ? evaluable
    if (( h_timeCourse_ALPHA  +  h_timeCourse_BETA ) == 0)  { 
        h_timeCourse_t = 0.0  *  h_timeCourse_TIME_SCALE ? evaluable cdv
    } else if (1/( ( h_timeCourse_ALPHA  +  h_timeCourse_BETA ) *  h_rateScale  )  < ( 0.5 ))  { 
        h_timeCourse_t = ( (0.5 *  h_rateScale ) ) *  h_timeCourse_TIME_SCALE ? evaluable cdv
    } else  { 
        h_timeCourse_t = ( 1/( h_timeCourse_ALPHA  +  h_timeCourse_BETA )  ) *  h_timeCourse_TIME_SCALE ? evaluable cdv
    }
    
    h_q10Settings_q10 = h_q10Settings_q10Factor ^((temperature -  h_q10Settings_experimentalTemp )/ h_q10Settings_TENDEGREES ) ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=h type=gateHHratesTauInf), from q10Settings; Component(id=null type=q10ExpTemp)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10ExpTemp)]))
    h_rateScale = h_q10Settings_q10 ? path based
    
    ? DerivedVariable is based on path: forwardRate/r, on: Component(id=h type=gateHHratesTauInf), from forwardRate; Component(id=null type=HHExpLinearRate)
    h_alpha = h_forwardRate_r ? path based
    
    ? DerivedVariable is based on path: reverseRate/r, on: Component(id=h type=gateHHratesTauInf), from reverseRate; Component(id=null type=HHExpLinearRate)
    h_beta = h_reverseRate_r ? path based
    
    ? DerivedVariable is based on path: steadyState/x, on: Component(id=h type=gateHHratesTauInf), from steadyState; Component(id=null type=HHSigmoidVariable)
    h_inf = h_steadyState_x ? path based
    
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=h type=gateHHratesTauInf), from timeCourse; Component(id=null type=NaxSH10_ChannelML_h_tau_tau)
    h_tauUnscaled = h_timeCourse_t ? path based
    
    h_tau = h_tauUnscaled  /  h_rateScale ? evaluable
    h_fcond = h_q ^ h_instances ? evaluable
    
     
    rate_m_q = ( m_inf  -  m_q ) /  m_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
     
    
     
    rate_h_q = ( h_inf  -  h_q ) /  h_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
     
    
     
    
     
    
}

