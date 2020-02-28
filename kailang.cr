ARGV.each do |key|
    if key.ends_with?(".kai")
        filename = "#{key}"
        main filename
    else 
        puts "wrong file type"
    end
end

def main (filename)
    File.each_line filename do |line|
        puts line
        if line.starts_with?("p")
            puts "Found print function"
        end
        if line.starts_with?("f")
            puts "Found for/while loop"
        end
        if line.starts_with?("v")
            puts "found variable"
        end
        if line.starts_with?("e")
            puts "found end"
        end
    end
end
