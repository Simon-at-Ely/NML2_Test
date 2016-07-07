'''
Neuron simulator export for:

Components:
    null (Type: include)
    null (Type: include)
    null (Type: include)
    null (Type: include)
    null (Type: include)
    null (Type: include)
    null (Type: include)
    null (Type: include)
    hhcell (Type: cell)
    pulseGen1 (Type: pulseGenerator:  delay=0.1 (SI time) duration=0.1 (SI time) amplitude=8.000000000000001E-11 (SI current))
    net1 (Type: networkWithTemperature:  temperature=305.15 (SI temperature))
    null (Type: notes)
    NaxSH10_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    NaP_iAMC_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    Kdr_iAMC_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    KA_iAMC_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    LeakConductance (Type: ionChannelPassive:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    BK_IAMC_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    CaV_R_iAMC_ChannelML (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    null (Type: notes)
    Gran_CaPool_98 (Type: decayingPoolConcentrationModel:  restingConc=7.55E-5 (SI concentration) decayConstant=0.01 (SI time) shellThickness=8.4E-8 (SI length) Faraday=96485.3 (SI charge_per_mole) AREA_SCALE=1.0 (SI area) LENGTH_SCALE=1.0 (SI length))
    null (Type: include)
    network (Type: networkWithTemperature:  temperature=308.15 (SI temperature))
    Vm_Test (Type: Simulation:  length=1.0 (SI time) step=5.0E-5 (SI time))


    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.4.5
         org.neuroml.model   v1.4.5
         jLEMS               v0.9.8.5

'''

import neuron

import time
h = neuron.h
h.load_file("stdlib.hoc")

h.load_file("stdgui.hoc")

h("objref p")
h("p = new PythonObject()")

class NeuronSimulation():

    def __init__(self, tstop, dt):

        # Adding simulation Component(id=Vm_Test type=Simulation) of network/component: network (Type: networkWithTemperature:  temperature=308.15 (SI temperature))

        # Temperature used for network: 308.15 K
        h.celsius = 308.15 - 273.15

        print("Population hhpop contains 1 instance(s) of component: hhcell of type: cell")

        print("Setting the default initial concentrations for ca (used in hhcell) to 7.55E-5 mM (internal), 2.4 mM (external)")
        h("cai0_ca_ion = 7.55E-5")
        h("cao0_ca_ion = 2.4")

        h.load_file("hhcell.hoc")
        a_hhpop = []
        h("n_hhpop = 1")
        h("objectvar a_hhpop[n_hhpop]")
        for i in range(int(h.n_hhpop)):
            h("a_hhpop[%i] = new hhcell()"%i)
            h("access a_hhpop[%i].soma"%i)

        h("a_hhpop[0].position(0., 0., 0.)")

        h("proc initialiseV_hhpop() { for i = 0, n_hhpop-1 { a_hhpop[i].set_initial_v() } }")
        h("objref fih_hhpop")
        h('{fih_hhpop = new FInitializeHandler(0, "initialiseV_hhpop()")}')

        h("proc initialiseIons_hhpop() { for i = 0, n_hhpop-1 { a_hhpop[i].set_initial_ion_properties() } }")
        h("objref fih_ion_hhpop")
        h('{fih_ion_hhpop = new FInitializeHandler(1, "initialiseIons_hhpop()")}')

        trec = h.Vector()
        trec.record(h._ref_t)

        h.tstop = tstop

        h.dt = dt

        h.steps_per_ms = 1/h.dt



        # File to save: Volts_file
        # Column: hhpop/0/hhcell/v
        h(' objectvar v_V_Volts_file ')
        h(' { v_V_Volts_file = new Vector() } ')
        h(' v_V_Volts_file.record(&a_hhpop[0].soma.v(0.5)) ')
        h.v_V_Volts_file.resize((h.tstop * h.steps_per_ms) + 1)

        # File to save: time
        # Column: time
        h(' objectvar v_time ')
        h(' { v_time = new Vector() } ')
        h(' v_time.record(&t) ')
        h.v_time.resize((h.tstop * h.steps_per_ms) + 1)



    def run(self):

        sim_start = time.time()
        print("Running a simulation of %sms (dt = %sms)" % (h.tstop, h.dt))

        h.run()

        sim_end = time.time()
        sim_time = sim_end - sim_start
        print("Finished simulation in %f seconds (%f mins), saving results..."%(sim_time, sim_time/60.0))


        # File to save: time
        py_v_time = [ t/1000 for t in h.v_time.to_python() ]  # Convert to Python list for speed...

        f_time_f2 = open('time.dat', 'w')
        for i in range(int(h.tstop * h.steps_per_ms) + 1):
            f_time_f2.write('%f'% py_v_time[i])  # Save in SI units...+ '\n')
        f_time_f2.close()
        print("Saved data to: time.dat")

        # File to save: Volts_file
        py_v_V_Volts_file = [ float(x  / 1000.0) for x in h.v_V_Volts_file.to_python() ]  # Convert to Python list for speed, variable has dim: voltage

        f_Volts_file_f2 = open('Vm_Test.v.dat', 'w')
        for i in range(int(h.tstop * h.steps_per_ms) + 1):
            f_Volts_file_f2.write('%e\t'% py_v_time[i]  + '%e\t'%(py_v_V_Volts_file[i]) + '\n')
        f_Volts_file_f2.close()
        print("Saved data to: Vm_Test.v.dat")

        save_end = time.time()
        save_time = save_end - sim_end
        print("Finished saving results in %f seconds"%(save_time))

        print("Done")

        quit()
if __name__ == '__main__':

    ns = NeuronSimulation(tstop=1000, dt=0.05)

    ns.run()

