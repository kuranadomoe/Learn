--[=[	exercise.lua
--[=[	C语言风格的lua程序
--]=]
do

	--函数前向声明
	local main


	function main()
		print("Main function head.\n\n")

		print("Please input lines:")
		local lines = io.read("*number")
		local str = ""
		for i = 1,lines*lines,1 do
			local x,y = math.ceil(i/lines), i%lines ~= 0 and i%lines or lines
			if x == y or x+y-1 == lines then
				str = str .. "*"
			else
				str = str .. " "
			end
			if i%lines == 0 then
				str = str .. "\n"
			end
		end
		print("Graphics:\n" .. str .. "End.")

		print("\n\nMain function tail.")
		os.execute("pause")
	end


	--调用main函数(￣▽￣)"
	main()

end

