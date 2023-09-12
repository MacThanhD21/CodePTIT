
public class PhuHo {
    private String id, name, DOB;
    private double LT_Score, TH_Score;


    public PhuHo(int id, String name, String DOB, double LT_Score, double TH_Score) {
        this.id = "PH" + String.format("%02d", id);
        this.name = name;
        this.DOB = DOB;
        this.LT_Score = LT_Score;
        this.TH_Score = TH_Score;
    }
    
    public double getThuong_Score() {
        if(this.LT_Score >= 8 && this.TH_Score >= 8) {
            return 1.0;
        }
        else if(this.LT_Score >= 7.5 && this.TH_Score >= 7.5) {
            return 0.5;
        }

        return 0;
    }

    public int getTuoi() {
        int DOB = Integer.parseInt(this.DOB.substring(6));
        return 2021 - DOB;
    }
    
    public int getDiemXepLoai() {
        // Calculate the average of the two exam scores
        double averageScore = (this.TH_Score + this.LT_Score) / 2.0;

        // Add the bonus score and round to the nearest integer
        double totalScore = averageScore + this.getThuong_Score();
        int roundedScore = (int) Math.round(totalScore);

        // If the rounded score is greater than 10, set it to 10
        return Math.min(roundedScore, 10);
    }

    public String getRank() {
        int score = getDiemXepLoai();
        String rank;

        if (score < 5) {
            rank = "Truot";
        } else if (score >= 5 && score <= 6) {
            rank = "Trung binh";
        } else if (score == 7) {
            rank = "Kha";
        } else if (score == 8) {
            rank = "Gioi";
        } else {
            rank = "Xuat sac";
        }

        return rank;
    }


    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.getTuoi() + " " + this.getDiemXepLoai() + " " + this.getRank();
    }
}
