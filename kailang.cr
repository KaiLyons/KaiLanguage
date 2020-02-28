ARGV.each do |key|
    if key.ends_with?(".kai")
        filename = "#{key}"
        main filename
    else 
        puts "wrong file type"
    end
end

def print(line)
    line = line.split("p", remove_empty: true)
    line = line.join(",")
    line = line.lstrip()
    line = line.strip("\"")
    puts line
end

def main (filename)
    File.each_line filename do |line|
        if line.starts_with?("p")
            print line
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
