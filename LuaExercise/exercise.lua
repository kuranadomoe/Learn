--[=[	exercise.lua
--[=[	C语言风格的lua程序
--]=]
do

	--函数前向声明
	local main

	i = 0
	function test()
		return function() return i end
	end
	i = 10
	foo = test()
	print(foo())

	function main()
		print("Main function head.\n\n")

		local num,counter = io.read("*num"),0
		for zeroNum in function(status,var)
							local temp = math.floor(var/5)
							if temp > 0 then
								return temp
							else
								return nil
							end
						end,nil,num
		do
			counter = counter + zeroNum
		end
		print(counter)

		print("\n\nMain function tail.")
		os.execute("pause")
	end


	--调用main函数(￣▽￣)"
	main()

end

