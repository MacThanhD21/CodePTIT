

public class J05019{
    
    static class TramDo{
        private String id, name, timeStart, timeEnd;
        private int rainFall;
        
        public TramDo(String id, String name, String timeStart, String timeEnd, int rainFall) {
            this.id = "T" + String.format("%.2d", id);
            this.name = name;
            this.timeStart = timeStart;
            this.timeEnd = timeEnd;
            this.rainFall = rainFall;
        }

        public double getTime(){
            double h = Integer.parseInt(this.timeEnd.substring(0,2)) - Integer.parseInt(this.timeStart.substring(0,2)) ;
            double m = (double) (Integer.parseInt(this.timeEnd.substring(3)) - Integer.parseInt(this.timeStart.substring(3))) / 60 ;
            return h + m;
        }

        void update(TramDo p){
            this.getTime() += p.getTime();
            this.rainFall += p.rainFall;
        }

        @Override
        public String toString() {
            return "{" +
                "}";
        }
        
    } 

    public static void main(String[] args) {
        
    }
}