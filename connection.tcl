#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red

#Open the NAM trace file

set nf [open o.nam w]
$ns namtrace-all $nf

# create nodes

set n0 [$ns node]
set n1 [$ns node]


#Create links between the nodes

$ns duplex-link $n0 $n1 2Mb 10ms DropTail

#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient right-down

#Define a 'finish' procedure

proc finish {} {
        global ns nf
        $ns flush-trace
        #Close the NAM trace file
        close $nf
        #Execute NAM on the trace file
        exec nam o.nam &
        exit 0
}


#Setup a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

#Setup a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


#Schedule events for the CBR and FTP agents
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"

#Detach tcp and sink agents (not really necessary)
$ns at 4.5 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n1 $sink"

#Call the finish procedure

$ns at 5.0 "finish"

#Run the simulation

$ns run