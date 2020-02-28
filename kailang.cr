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
    end
end
