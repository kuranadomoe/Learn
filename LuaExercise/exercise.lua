--[=[	exercise.lua
--[=[	C语言风格的lua程序
--]=]
do

	--函数前向声明
	local main


	function main()
		print("Main function head.\n\n")


		print("\n\nMain function tail.")
		os.execute("pause")
	end


	--调用main函数(￣▽￣)"
	main()

end

