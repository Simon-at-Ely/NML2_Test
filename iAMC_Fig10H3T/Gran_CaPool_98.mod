TITLE Mod file for component: Component(id=Gran_CaPool_98 type=decayingPoolConcentrationModel)

COMMENT

    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.5.0
         org.neuroml.model   v1.5.0
         jLEMS               v0.9.8.7

ENDCOMMENT

NEURON {
    SUFFIX Gran_CaPool_98
    USEION ca READ cai, cao, ica WRITE cai VALENCE 2
    RANGE cai
    RANGE cao
    GLOBAL initialConcentration
    GLOBAL initialExtConcentration
    RANGE restingConc                       : parameter
    RANGE decayConstant                     : parameter
    RANGE shellThickness                    : parameter
    RANGE Faraday                           : parameter
    RANGE AREA_SCALE                        : parameter
    RANGE LENGTH_SCALE                      : parameter
    RANGE effectiveRadius                   : derived variable
    RANGE innerRadius                       : derived variable
    RANGE shellVolume                       : derived variable
    
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
    surfaceArea (um2)
    iCa (nA)
    initialConcentration (mM)
    initialExtConcentration (mM)
    
    restingConc = 7.55E-5 (mM)
    decayConstant = 10 (ms)
    shellThickness = 0.084 (um)
    Faraday = 0.096485294 (C / umol)
    AREA_SCALE = 1.0E12 (um2)
    LENGTH_SCALE = 1000000 (um)
}

ASSIGNED {
    cai (mM)
    cao (mM)
    ica (mA/cm2)
    diam (um)
    area (um2)
    
    effectiveRadius (um)                   : derived variable
    
    innerRadius (um)                       : derived variable
    
    shellVolume (um3)                      : derived variable
    rate_concentration (mM/ms)
    
}

STATE {
    concentration (mM) 
    extConcentration (mM) 
    
}

INITIAL {
    initialConcentration = cai
    initialExtConcentration = cao
    rates()
    rates() ? To ensure correct initialisation.
    
    concentration = initialConcentration
    
    extConcentration = initialExtConcentration
    
}

BREAKPOINT {
    
    SOLVE states METHOD cnexp
    
    if (concentration  < 0) {
        concentration = 0 ? standard OnCondition
    }
    
    
}

DERIVATIVE states {
    rates()
    concentration' = rate_concentration
    cai = concentration 
    
}

PROCEDURE rates() {
    
    surfaceArea = area   : surfaceArea has units (um2), area (built in to NEURON) is in um^2...
    
    iCa = -1 * (0.01) * ica * surfaceArea :   iCa has units (nA) ; ica (built in to NEURON) has units (mA/cm2)...
    
    effectiveRadius = LENGTH_SCALE  * sqrt(surfaceArea/(  AREA_SCALE   * (4 * 3.14159))) ? evaluable
    innerRadius = effectiveRadius  -  shellThickness ? evaluable
    shellVolume = (4 * (  effectiveRadius   *  effectiveRadius  *   effectiveRadius  ) * 3.14159 / 3) - (4 * (  innerRadius   *  innerRadius  *   innerRadius  ) * 3.14159 / 3) ? evaluable
    rate_concentration = iCa / (2 *  Faraday  *   shellVolume  ) - ((  concentration   -   restingConc  ) /   decayConstant  ) ? Note units of all quantities used here need to be consistent!
    
     
    
}

