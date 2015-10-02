Roll_array = #()
Pitch_array = #()
Yaw_array = #()
Alti_array = #()
in_name = "C:\Users\A.Barredo\Desktop\Skate\Samples\Sample2.dat"
in_file = openFile in_name 
if in_file != undefined then (
	print "Inside"
	num_Frames = readValue in_file
	animationRange = interval 0 num_Frames
	Roll_array.count = num_Frames
	Pitch_array.count = num_Frames
	Yaw_array.count = num_Frames
	Alti_array.count = num_Frames
	for v = 1 to num_Frames do
 (
	
	 for vi = 1 to 4 do
	(
		rotValue = readValue in_file
		case vi of 
		(
			1: Roll_array[v] = rotValue as float
			2: Pitch_array[v] = rotValue as float
			3: Yaw_array[v] = rotValue as float
			4: Alti_array[v] = rotValue as float
		)
	)
 )
	min = 0 as float
	for vi = 1 to num_Frames do
	(
		print Roll_array[vi]
		 if Alti_array[vi] < min  do (
			 min = Alti_array[vi]
		 )
	)
	for vi = 1 to num_Frames do
	(
		Alti_array[vi] = Alti_array[vi]+0.58
	)
	print "Finished"
)

for v = 1 to num_Frames do
 (
	 $tabla.rotation.controller.x_rotation = Roll_array[v]-90
	 $RuedaDI.rotation.controller.x_rotation = Roll_array[v]-90
	 $RuedaAI.rotation.controller.x_rotation = Roll_array[v]-90
	 $tabla.rotation.controller.y_rotation = Pitch_array[v]
	 $RuedaDI.rotation.controller.y_rotation = Pitch_array[v]
	 $RuedaAI.rotation.controller.y_rotation = Pitch_array[v]
	 $tabla.rotation.controller.z_rotation = Yaw_array[v] 
	 $RuedaDI.rotation.controller.z_rotation = Yaw_array[v] 
	 $RuedaAI.rotation.controller.z_rotation = Yaw_array[v] 
	 $tabla.position.controller.z_position = Alti_array[v]*10
	 $RuedaDI.position.controller.z_position = Alti_array[v]*10
	 $RuedaAI.position.controller.z_position = Alti_array[v]*10
	 completeRedraw()
	 sliderTime += 1
 )

close in_file